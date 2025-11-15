select name as Customers
from customers
except
select name
from customers
join
orders
on customers.id=orders.customerid;
