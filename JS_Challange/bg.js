const body = document.querySelector("body");

const IMG_NUMBER = 4;

function paintImage(imgnumber){
    const image = new Image();
    image.src = `images/${imgnumber + 1}.jpg`;
    image.classList.add("bgImage");
    body.appendChild(image);
}

function genRandum(){
    const number = Math.floor(Math.random() * IMG_NUMBER);
    return number;
}

function init(){
    const randonNumber = genRandum();
    paintImage(randonNumber);
}

init();
