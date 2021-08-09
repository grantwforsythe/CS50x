document.addEventListener("DOMContentLoaded", function(){
    let button = document.querySelectorAll('button');
    // TODO: reset the colors of none selected buttons
    for (let i = 0; i < button.length; i++){
        button[i].addEventListener("click", function () {
            // this is an instance of an event object
            if (this.id === "two"){
                this.style.background = "green";
            } else {
                this.style.background = "red";
            }
        });
    }
});