import java.io.*; 
import java.net.*;

class ClientThreadREST
{    
    public static void main(String args[])
    {
        if(args.length < 3)    {
            System.out.println("USAGE: java ClientREST tipofunzione op1 op2");
        }   
        else  {

            if(args[0].equals("calcola-somma")) {
                RESTAPI service1=new RESTAPI("127.0.0.1", 8000, args[0], args[1], args[2]);
                service1.start();
            }
            else if(args[0].equals("calcola-primi"))    {

                int min = Integer.parseInt(args[1]);
                int max = Integer.parseInt(args[2]);
                int a = min+(max-min)/3;
                int b = min+(max-min)/3+(max-min)/3;

                RESTAPI service1=new RESTAPI("127.0.0.1", 8000, args[0], args[1], Integer.toString(a));
                RESTAPI service2=new RESTAPI("127.0.0.1", 8001, args[0], Integer.toString(a+1), Integer.toString(b));
                RESTAPI service3=new RESTAPI("127.0.0.1", 8002, args[0], Integer.toString(b+1), args[2]);
                service1.start();
                service2.start();
                service3.start();
            }
            else    {
                System.out.println("USAGE: java ClientREST tipofunzione op1 op2");
            }
            
        }
    }
}

class RESTAPI extends Thread
{
    String server, service, param1, param2;
    int port;

    public void run()   {
        if(service.equals("calcola-somma"))    {
            System.out.println("Risultato: " + calcolaSomma(Float.parseFloat(param1), Float.parseFloat(param2)));
        }
        else if(service.equals("calcola-primi"))    {
            System.out.println("Sono stati trovati " + calcolaPrimi(Integer.parseInt(param1), Integer.parseInt(param2)) + " numeri primi");
        }
        else    {
            System.out.println("Servizio non disponibile!");
        }

    }

    RESTAPI(String remoteServer, int port, String srvc, String p1, String p2)  {
        this.server = new String(remoteServer);
        this.port = port;
        this.service = new String(srvc);
        this.param1 = new String(p1);
        this.param2 = new String(p2);
    }

    synchronized float calcolaSomma(float val1, float val2)  {

        URL u = null;
        float risultato=0;
        int i;

        try 
        { 
            u = new URL("http://"+server+":"+port+"/calcola-somma?param1="+val1+"&param2="+val2);
            System.out.println("URL aperto: " + u);
        }
        catch (MalformedURLException e) 
        {
            System.out.println("URL errato: " + u);
        }

        try 
        {
            URLConnection c = u.openConnection();
            c.connect();
            BufferedReader b = new BufferedReader(new InputStreamReader(c.getInputStream()));
            System.out.println("Lettura dei dati...");
            String s;
            while( (s = b.readLine()) != null ) {
                System.out.println(s);
                if((i = s.indexOf("somma"))!=-1)
                    risultato = Float.parseFloat(s.substring(i+7));
            }
        }
        catch (IOException e) 
        {
            System.out.println(e.getMessage());
        }
    
        return (float)risultato;
    }    

    synchronized int calcolaPrimi(int val1, int val2)  {

        URL u = null;
        int cont = 0;

        try 
        { 
            u = new URL("http://"+server+":"+port+"/calcola-primi?param1="+val1+"&param2="+val2);
            System.out.println("URL aperto: " + u);
        }
        catch (MalformedURLException e) 
        {
            System.out.println("URL errato: " + u);
        }

        try 
        {
            URLConnection c = u.openConnection();
            c.connect();
            BufferedReader b = new BufferedReader(new InputStreamReader(c.getInputStream()));
            System.out.println("Lettura dei dati...");
            String s;
            while( (s = b.readLine()) != null ) {
                System.out.println(s);
                cont++;
            }
        }
        catch (IOException e) 
        {
            System.out.println(e.getMessage());
        }
    
        return cont-2;
    }


}
