# Write your MySQL query statement below
WITH no_banned AS (
    SELECT users_id
    FROM Users
    WHERE banned = 'No'
),
all_info AS (
    SELECT t.client_id, t.driver_id, t.status, t.request_at
    FROM Trips t
    JOIN no_banned client ON t.client_id = client.users_id
    JOIN no_banned driver ON t.driver_id = driver.users_id
    WHERE request_at BETWEEN '2013-10-01' AND '2013-10-03'
)

SELECT request_at as 'Day',
 ROUND(COUNT(CASE WHEN status != 'completed' THEN 1 END)/(COUNT(*)), 2) as 
'Cancellation Rate'
FROM all_info o
GROUP BY request_at;


