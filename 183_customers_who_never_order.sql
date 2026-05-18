# Write your MySQL query statement below
SELECT Customers.name AS Customers
FROM Customers LEFT JOIN Orders ON Customers.id = Orders.customerId
WHERE Orders.id IS NULL;

# The following one is faster:
#SELECT name as Customers
#from Customers
#where id not in (
#    select customerId
#    from Orders
#);
