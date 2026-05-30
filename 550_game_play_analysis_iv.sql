# Write your MySQL query statement below
WITH ranked AS (
    SELECT player_id, 
           event_date, 
           DENSE_RANK() OVER (PARTITION BY player_id ORDER BY event_date 
ASC) as ranks
    FROM Activity
),
first AS (
    SELECT player_id, event_date
    FROM ranked
    WHERE ranks = 1
),
second AS (
    SELECT player_id, event_date
    FROM ranked
    WHERE ranks = 2
)
SELECT ROUND(COUNT(CASE WHEN day_1.event_date = day_2.event_date - 
INTERVAL 1 DAY THEN 1 END)/COUNT(*), 2) as fraction
FROM first day_1 LEFT JOIN second day_2 ON day_1.player_id = 
day_2.player_id;
