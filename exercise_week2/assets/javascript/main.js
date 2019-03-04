document.getElementById("asidebutton").addEventListener("click", zoomArticle);
document.getElementById("backgroundmusic").volume = 0.2;


function zoomArticle() {
    document.getElementById('main_article').classList.toggle('full');
    document.getElementById("backgroundmusic").play();
}