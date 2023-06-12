server = {
    url: 'http://localhost:5555/login'
}

function login(event) {
    welcomeDiv = document.getElementById('welcome'); // completare
    loginForm = document.getElementById('login'); // completare

    alert("PROVA");

    // recupero i valori di username e password dal form
    username = document.getElementById('username').value; // completare
    password = document.getElementById('password').value; // completare
    window.alert("Prova");

    // esegue una richiesta ajax
    $.ajax({
        url: 'http://localhost:5555/login', // complerare
        type: 'POST', // completare con il metodo, GET o POST
        data: {username: username, password: password},
        success: function(res) {
            loginForm.style.display = "block"
            welcomeDiv.style.display = "none"
            // nascondere il form di login
            // mostrare il div di benvenuto, deve contenere un pulsante per effettuare il logout (richiama il metodo logout)
        },
        error: function(res) {
            // mostrare errore a video
            console.error(res);
        }
    });

    event.preventDefault();
}

function logout() {
    // mostrare il form di login
    // nascondere il div di benvenuto
}

function showPassword() {
   // completare
}
