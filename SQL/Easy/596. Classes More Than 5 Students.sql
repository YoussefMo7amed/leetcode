select c1.class from courses c1
group by c1.class
having count(c1.student) >= 5
