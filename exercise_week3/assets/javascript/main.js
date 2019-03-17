let meal_btn_list = ["assets/images/DongPoRou_Btn.png", "assets/images/Fish_Btn.png", "assets/images/FoTiaoQiang_Btn.png",
                     "assets/images/LengPan_Btn.png", "assets/images/MiGao_Btn.png", "assets/images/Vegetable_Btn.png"];
let meal_image_list = ["assets/images/DongPoRou_Food.png", "assets/images/Fish_Food.png", "assets/images/FoTiaoQiang_Food.png",
                        "assets/images/LengPan_Food.png", "assets/images/MiGao_Food.png", "assets/images/Vegetable_Food.png"];
let meal_title_list = ["東坡肉", "清蒸魚", "佛跳牆", "冷盤", "紅蟳荷葉米糕", "炒青菜"];
let meal_intro_list = ["正統的東坡肉，油而不膩，入口即化，一口接一口，讓人無法放下筷子。</br>提到東坡肉的來源，跟中國宋代的大文豪「蘇東坡」有著密不可分的關係。</br>蘇東坡，名軾，字子瞻，是個文學家兼美食家，不只為後代留下了許多美妙的詩詞，更留下了這道美味的佳餚。", 
                       "魚象徵著繁榮和盈餘( 年年有魚 )。</br>除夕這一天人們準備除舊迎新，吃團圓飯。</br>家人的團聚往往令一家之主在精神上得到安慰與滿足，老人家眼看兒孫滿堂，一家大小共敘天倫，過去的關懷與撫養子女所付出的心血總算沒有白費，這是何等的幸福。</br>而年輕一輩，也正可以藉此機會向父母的養育之恩表達感激之情", 
                       "清光緒年間，一福州官錢局官員在家宴請福建按察使周蓮，主料為雞、鴨、豬等約為十多種，用紹興酒罈精心煨製而成。</br>周蓮品嘗後讚不絕口，問及菜名，該官員說該菜取「吉祥如意、福壽雙全」之意，名「福壽全」。</br>另一說，「福壽全」的福州腔似「佛跳牆」，遂以訛傳訛至今。", 
                       "共七道冷盤，</br>有大肉、烏魚子、蝦棗丸、螺肉、滷豬舌、海蜇花、松阪豬，承裝的七仙女盤，</br>七仙女寓意吉祥，七道食物的烹調方式不同，食材也不重複，考驗總舖師的底蘊",
                       "紅蟳米糕源自福建福州的名菜，當地稱為八寶蟳飯或紅蟳八寶飯，</br>我們今天吃的這個是用舊米、蓮子、蛋黃、蝦米等料在蒸籠內去蒸，整個紅蟳的蟹黃也都很飽滿，</br>這道米糕是對於時間的敬意，也是考驗師傅對於選材能力",
                       "只要是炒青菜，空心菜、莧菜、湯匙菜、野蓮或高麗菜等菜蔬的烹調手法大同小異</br>–菜莖菜葉挑揀開來，武火燒鍋下冷油與鹽，依據不同的菜蔬爆香蒜末、辣椒或薑絲增添層次香氣，</br>先炒莖再炒葉，起鍋前噴灑些許米酒即可。</br>因為是高溫爆炒，拋鍋翻滾不出幾分鐘便該盛盤，炒青菜就是該熱呼呼地吃才過癮"];
let meal_num = 0;

$(document).ready(() => { 
    $('header').transition('fade down', 0, ()=>{
        $('article').transition('fade down', 0, () => {
            $('nav').transition('fade up', 0)
        });
    });
});


/* Preventing transition on resizing the page */
$(window).on('resize', () =>{
    $('nav').removeClass('welcome_page')
    $('#main_table').removeClass('welcome_page')
    $('.main_chair').removeClass('welcome_page')
});

/* Clicking chairs will toggle main & menu */
$('.main_chair').click(() => {
    $('header').transition('fade down', 2000);
    $('article').transition('fade down', 2000);
    $('nav').addClass('welcome_page').toggleClass('expand');
    $('#main_table').addClass('welcome_page').toggleClass('expand');
    $('.main_chair').addClass('welcome_page').toggleClass('expand');
    meal_num = 0;
    $('#meal_btn').attr('src', meal_btn_list[meal_num]);
    $('.menu').transition('scale', 2000);
});

$('#left_btn').click(() => {
    --meal_num;
    if(meal_num < 0)
        meal_num = meal_btn_list.length-1;
    $('#meal_btn').attr('src', meal_btn_list[meal_num]);
});

$('#right_btn').click(() => {
    ++meal_num;
    if(meal_num >= meal_btn_list.length)
        meal_num = 0;
    $('#meal_btn').attr('src', meal_btn_list[meal_num]);
});

$('#meal_btn').click(() => {
    $('#meal_image').attr('src', meal_image_list[meal_num]);
    $('#meal_title').html(meal_title_list[meal_num]);
    $('#meal_intro').html(meal_intro_list[meal_num]);
    $('.detail').transition('scale', 1000);
});

$('#detail_back_btn').click(() => {
    $('.detail').transition('scale', 1000);
});


