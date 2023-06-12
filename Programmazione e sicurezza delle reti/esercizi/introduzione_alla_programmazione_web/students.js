server = {
    url: ''
}

function getStudents() {
    $.ajax({
        url: '', // completare
        type: '', // completare
        dataType: 'json',
        headers: {
            Accept: "application/json", // specifica che la risposta deve essere in formato json
        },
        success: function(res) {
            // completare, mostrare i dati
        },
        error: function(res) {
            // mostrare errore a video
            console.error(res);
        }
    });
}