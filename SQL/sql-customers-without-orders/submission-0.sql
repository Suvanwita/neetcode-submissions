-- Write your query below
select customers.name from customers full outer join orders on customers.id=orders.customer_id where orders.id is NULL;