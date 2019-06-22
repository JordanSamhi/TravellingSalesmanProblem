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
	 * M�thode MAIN
	 * @param args
	 * 		Les arguments pass�s � la m�thode main
	 * @throws Exception
	 * 		Permet de g�rer les diverses exceptions
	 * 		
	 */
	public static void main(String[] args) throws Exception{
		/**
		 * ServerSocket  permettant la connexion avec le client
		 */
		ServerSocket serveur;
		serveur = new ServerSocket(9161); 
		
		System.out.println("serveur de majuscule d�marr� : "+serveur);
		
		/**
		 * Adresse locale de la machine sur laquelle
		 * est lanc�e le serveur
		 */
		InetAddress cetteMachine;
		/**
		 * Port sur lequel le serveur doit �couter
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
				 * Socket pour le nouveau client connect�
				 */
				Socket nouveauClientSocket;
				/**
				 * Instanciation de la classe ReceveurEnvoyeur
				 * pour lancer un thread par client
				 */
				ReceveurEnvoyeur nouveauClientThread;
				
				nouveauClientSocket = serveur.accept(); 
				++noConnexion;
				System.out.println("Connexion r�ussie n� : "+noConnexion);
				
				nouveauClientThread = new ReceveurEnvoyeur(nouveauClientSocket, groupe, noConnexion); 
				nouveauClientThread.start();
			}
			catch(SocketException erreur){
				serveur.close();
			}
		}
	}
}
