# Write your MySQL query statement below
SELECT Product.product_name, Sales.year,Sales.price from Sales,Product
WHERE Sales.product_id=Product.product_id