# Write your MySQL query statement below
WITH salary_and_departmentId AS (
    SELECT e.departmentId, d.name, MAX(salary) AS maxSalary
    FROM Employee e LEFT JOIN Department d ON e.departmentId = d.id
    GROUP BY departmentId
)
SELECT s.name AS Department, 
       e.name AS Employee, 
       e.salary AS Salary
FROM Employee e LEFT JOIN salary_and_departmentId s
ON e.departmentId = s.departmentId
WHERE e.salary = s.maxSalary;
