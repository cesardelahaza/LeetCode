# Write your MySQL query statement below
WITH groups_by AS (
    SELECT customer_number, COUNT(*) AS counts
    FROM Orders
    GROUP BY customer_number
    ORDER BY counts DESC
)

SELECT customer_number
FROM groups_by
LIMIT 1;
