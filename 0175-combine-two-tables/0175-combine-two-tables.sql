select firstname , lastname , city , state from 
person as p left outer join 
address  as a
on p.personid = a.personid;