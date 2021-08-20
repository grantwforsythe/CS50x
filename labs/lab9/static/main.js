document.addEventListener("DOMContentLoaded", function(){
    document.getElementById("submit").addEventListener("submit", verify); 

    function verify() {
        let name = document.getElementById("adduser").elements["name"]
        let month = document.getElementById("adduser").elements["month"]
        let day = document.getElementById("adduser").elements["day"]

        // checks if there is any digits in the name
        if (name.match(/[0-9]/) != null){
            alert("Please enter a vaild name.");
            name.value = ''; 
            return false;
        }

        // capitalize the first letter in the string
        name.toLowerCase().trim().replace(/^\w/, (c) => c.toUpperCase());
    }

});