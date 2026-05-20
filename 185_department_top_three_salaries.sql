# Write your MySQL query statement below
WITH ordered AS (
    SELECT departmentId,
           name AS Employee, 
           salary AS Salary, 
           DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary 
DESC) AS d_rank
    FROM Employee
)

SELECT d.name AS Department, o.Employee, o.Salary
FROM ordered o LEFT JOIN Department d ON o.departmentId = d.id
WHERE o.d_rank <= 3;
