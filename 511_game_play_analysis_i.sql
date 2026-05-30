# Write your MySQL query statement below
WITH ordered AS (
    SELECT player_id, event_date, DENSE_RANK() OVER (PARTITION BY 
player_id ORDER BY event_date ASC) as ranks
    FROM Activity
)
SELECT player_id, event_date as first_login 
FROM ordered
WHERE ranks = 1;
