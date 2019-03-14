let mainChairs = document.getElementsByClassName("main_chair");
for(let i = 0; i < mainChairs.length; ++i) {
    mainChairs[i].addEventListener("click", change_to_menu);
}
const header = document.getElementsByTagName("header")[0];
const article = document.getElementsByTagName("article")[0];
const nav = document.getElementsByTagName('nav')[0];

function change_to_menu() {
    header.classList.toggle('invisible');
    article.classList.toggle('invisible');
    nav.classList.toggle('expand');
}