$(document).ready(function() {
  //for list students
  $('#ajax_list_stu button[type="submit"]').click((event) => {
    event.preventDefault()    //This cancel default event when click submit, originally will change url
    $.ajax({
      url: "students.json",
      type: "GET",
      async: true,
      dataType: "json",
      success: function(data) {
        $(`#ajax_list_stu_output`).empty();
        $.each(data, function(key, value){ 
          $(`#ajax_list_stu_output`).append(`"${key}":"${value}"<br>`);
        });
      },
      error:function(xhr){
        alert("ERROR: " + xhr.status + " " + xhr.statusText);
      }
    });
  });

  //for search id
  $('#ajax_search_stu button[type="submit"]').click((event) => {
    event.preventDefault()    //This cancel default event when click submit, originally will change url
    $.ajax({
      url: "students.json",
      type: "GET",
      async: true,
      dataType: "json",
      success: function(data) {
        $(`#ajax_search_stu_output`).empty();
        let found = false;
        $.each(data, function(key, value){ 
          if($('#ajax_search_stu input[name=search_id]').val() === key) {
            found = true;
            $.get('/search', {
              name: value
            }, (search_data) => {
              $(`#ajax_search_stu_output`).html(search_data);
            });
          }
        });
        if(found === false)
          alert('ID not found');
      },
      error:function(xhr){
        alert("ERROR: " + xhr.status + " " + xhr.statusText);
      }
    });
  });

  //for add students
  $('#ajax_add_stu button[type="submit"]').click((event) => {
    event.preventDefault()    //This cancel default event when click submit, originally will change url
    $.ajax({
      url: "students.json",
      type: "GET",
      async: true,
      dataType: "json",
      success: function(data) {
        if($('#ajax_add_stu input[name=add_id]').val() !== "" && $('#ajax_add_stu input[name=add_name]').val() !== "")
          data[$('#ajax_add_stu input[name=add_id]').val()] = $('#ajax_add_stu input[name=add_name]').val();
        $.get('/add', data);
      },
      error:function(xhr){
        alert("ERROR: " + xhr.status + " " + xhr.statusText);
      }  
    });
  });

  //for delete students
  $('#ajax_delete_stu button[type="submit"]').click((event) => {
    event.preventDefault()    //This cancel default event when click submit, originally will change url
    $.ajax({
      url: "students.json",
      type: "GET",
      async: true,
      dataType: "json",
      success: function(data) {
        let found = false;
        $.each(data, function(key, value){ 
          if($('#ajax_delete_stu input[name=delete_id]').val() === key) {
            found = true;
            delete data[key];
          }
        });
        if(found === false)
          alert('ID not found, can\'t remove');
        $.get('/delete', data);
      },
      error:function(xhr){
        alert("ERROR: " + xhr.status + " " + xhr.statusText);
      }  
    });
  });

});
