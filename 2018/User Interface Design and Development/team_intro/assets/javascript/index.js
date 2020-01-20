let intro_list = ["./assets/resources/images/intro/1.jpg", 
                  "./assets/resources/images/intro/2.jpg", 
                  "./assets/resources/images/intro/3.jpg", 
                  "./assets/resources/images/intro/4.jpg", 
                  "./assets/resources/images/intro/5.jpg" ];

$('#member_pic_1').click(() => { 
    $('#intro_img').attr('src', intro_list[0]);
    $('#intro').fadeIn(1000);
    $('#intro_img').fadeIn(1000);
});

$('#member_pic_2').click(() => { 
    $('#intro_img').attr('src', intro_list[1]);
    $('#intro').fadeIn(1000);
    $('#intro_img').fadeIn(1000);
});

$('#member_pic_3').click(() => { 
    $('#intro_img').attr('src', intro_list[2]);
    $('#intro').fadeIn(1000);
    $('#intro_img').fadeIn(1000);
});

$('#member_pic_4').click(() => { 
    $('#intro_img').attr('src', intro_list[3]);
    $('#intro').fadeIn(1000);
    $('#intro_img').fadeIn(1000);
});

$('#member_pic_5').click(() => { 
    $('#intro_img').attr('src', intro_list[4]);
    $('#intro').fadeIn(1000);
    $('#intro_img').fadeIn(1000);
});

$('#close_btn').click(() => { 
    $('#intro').fadeOut(1000);
    $('#intro_img').fadeOut(1000, () => {
        $('#intro_img').attr('src', "");
    });
});