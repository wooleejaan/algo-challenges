select 
    ds.id, ds.email, ds.first_name, ds.last_name
from 
    developers ds
where 
    skill_code & (select code from skillcodes where name = 'Python')
    or skill_code & (select code from skillcodes where name = 'C#')
order by id;