-- �ڵ带 �Է��ϼ���
SELECT CART_ID, 
(
    case when sum(PRICE)<'50000' then sum(PRICE)+3000
    else sum(PRICE)
    end
) as ������
from CART_PRODUCTS
group by CART_ID
order by CART_ID;