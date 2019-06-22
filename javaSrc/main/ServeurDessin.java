package main;

import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;

/**
 * Classe principale du serveur, elle contient le MAIN
 *
 */
public class ServeurDessin{
	/**
	 * Méthode MAIN
	 * @param args
	 * 		Les arguments passés à la méthode main
	 * @throws Exception
	 * 		Permet de gérer les diverses exceptions
	 * 		
	 */
	public static void main(String[] args) throws Exception{
		/**
		 * ServerSocket  permettant la connexion avec le client
		 */
		ServerSocket serveur;
		serveur = new ServerSocket(9161); 
		
		System.out.println("serveur de majuscule démarré : "+serveur);
		
		/**
		 * Adresse locale de la machine sur laquelle
		 * est lancée le serveur
		 */
		InetAddress cetteMachine;
		/**
		 * Port sur lequel le serveur doit écouter
		 */
		int portLocal;
		/**
		 * Groupe de thread
		 */
		ThreadGroup groupe;
		
		portLocal = serveur.getLocalPort();
		
		cetteMachine = InetAddress.getLocalHost();
		
		System.out.println("adresse IP du serveur de majuscule : "+cetteMachine.getHostAddress());
		System.out.println("port du serveur : "+portLocal);
		
		groupe = new ThreadGroup("socketsClients");
		int noConnexion = 0;
		while(true){
			try{
				/**
				 * Socket pour le nouveau client connecté
				 */
				Socket nouveauClientSocket;
				/**
				 * Instanciation de la classe ReceveurEnvoyeur
				 * pour lancer un thread par client
				 */
				ReceveurEnvoyeur nouveauClientThread;
				
				nouveauClientSocket = serveur.accept(); 
				++noConnexion;
				System.out.println("Connexion réussie n° : "+noConnexion);
				
				nouveauClientThread = new ReceveurEnvoyeur(nouveauClientSocket, groupe, noConnexion); 
				nouveauClientThread.start();
			}
			catch(SocketException erreur){
				serveur.close();
			}
		}
	}
}
