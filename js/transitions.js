titleToStart = () => {
    document.getElementById("main-page").style.display = "none";
    document.getElementById("startup-page").style.display = "inline";
}

startToFreePlay = () => {
    document.getElementById("startup-page").style.display = "none";
    document.getElementById("freePlay").style.display = "inline";
    document.getElementById("noel").style.display = "none";
}

startToColors = () => {
    document.getElementById("startup-page").style.display = "none";
    document.getElementById("colors-page").style.display = "inline";
}

startToPlayback = () => {
    document.getElementById("playback-page").style.display = "inline";
    document.getElementById("startup-page").style.display = "none";
}

freePlaytoStart = () => {
    document.getElementById("freePlay").style.display = "none";
    document.getElementById("startup-page").style.display = "inline";
    document.getElementById("noel").style.display = "inline";
}

colorToStart = () => {
    document.getElementById("colors-page").style.display = "none";
    document.getElementById("startup-page").style.display = "inline";
}

playbackToStart = () => {
    document.getElementById("playback-page").style.display = "none";
    document.getElementById("startup-page").style.display = "inline";
}