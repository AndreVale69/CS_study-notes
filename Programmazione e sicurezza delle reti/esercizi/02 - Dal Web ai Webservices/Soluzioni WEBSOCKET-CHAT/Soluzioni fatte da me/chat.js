//Client

var name= prompt("What's your name?");
while(name==""){
    name=prompt("You have to choose a name. \n What's your name?")
}

// Query DOM
var message = document.getElementById('message'),
   sender = document.getElementById('sender'),
   btn = document.getElementById('send'),
   output = document.getElementById('output'),
   feedback = document.getElementById('feedback');

sender.innerHTML=name;  
sender.value=name;

// Invio richiesta di connessione al server
var webSocket = io.connect();

// Trigger with event key down
message.onkeydown = function(e) {
   e = e || window.event;
   webSocket.emit('typing', {
      sender: sender.value
   })
}

// Listen for events
btn.addEventListener('click', function(){
   if (message.value!="" ){    
 	   webSocket.emit('message', {
         message: message.value,
         sender: sender.value,
 	   });
 	   message.value = "";
   }
});

// UploadChat event
webSocket.on('UploadChat', function(data){
   feedback.innerHTML = '';
   var current_date = new Date(); 
   output.innerHTML += '<p>' + 'Time: ' + current_date.getHours() + ':' 
                     + current_date.getMinutes() + ':'
                     + current_date.getSeconds() 
                     + ' - ' + '<strong>' + data.sender 
                     + ': </strong>' + data.message + '</p>';
});

// Typing event
webSocket.on('typing', function(data){
   var current_date = new Date(); 
      feedback.innerHTML = '<p>' + 'Time: ' + current_date.getHours() + ':' 
                        + current_date.getMinutes() + ':'
                        + current_date.getSeconds() 
                        + ' - ' + '<strong>' + data.sender 
                        + ': </strong>' + 'typing...' + '</p>';
})