-- 코드를 입력하세요
SELECT CART_ID, 
(
    case when sum(PRICE)<'50000' then sum(PRICE)+3000
    else sum(PRICE)
    end
) as 결제액
from CART_PRODUCTS
group by CART_ID
order by CART_ID;