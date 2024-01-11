# Write your MySQL query statement below
select name, sum(transactions.amount) as balance from users 
  inner join transactions
  on transactions.account = users.account
  group by transactions.account
  having balance > 10000