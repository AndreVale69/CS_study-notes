bool result = false;
int backoff_time = randInt()
// finche' non sono stati trasmetti i dati, si rimane nel loop
while (not (result))
{
    // si controlla se il canale e' libero (true se libero, alt. false)
    if channel_is_free{
        // inizia la trasmissione dei dati, ma in parallelo...
        send_data()
        // ... viene ascoltato il canale durante invio dei dati.
        result = listen_channel()
        // se la funzione rileva un altro host che prova ad inviare un dato
        // ritorna il valore "false" e dunque attende un tempo chiamato backoff time.
        // Ovviamente se listen_channel esegue un return prima della fine di send_data(),
        // vuol dire che un altro host ha provato a comunicare, altrimenti terminano insieme.
        // Si assume che send_data() possa far terminare il processo listen_channel() tramite
        // un segnale. In tal caso, la funzione listen_channel() ritorna true
    }
    // result uguale a false solo se il canale non e' libero oppure se l'invio dei dati e'
    // stato disturbato da un altro host (quindi listen_channel() ha bloccato l'esecuzione tornando false)
    if result == False
        timeout(random_time)
    else
        output("Tutto corretto")
}