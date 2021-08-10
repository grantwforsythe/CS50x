document.addEventListener("DOMContentLoaded", function(){
    let button = document.querySelectorAll('button');
    let answer = document.createElement('p');
    for (let i = 0; i < button.length; i++){
        button[i].addEventListener("click", function () {
            // this is an instance of an event object
            for (let j = 0; j < button.length; j++){
                button[j].style.backgroundColor = "#d9edff";
                answer.remove()
            } 

            if (this.id === "two") {
                this.style.background = "green";
                answer.textContent = "Correct!";
            } else {
                this.style.background = "red";
                answer.textContent = "Incorrect";
            }
            this.append(answer);
        });
    }
});