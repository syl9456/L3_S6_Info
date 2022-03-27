package tchatche;
import java.util.ArrayList;
import tchatche.Message;

public class GestionMessages {
	
	public ArrayList<Message> ajouteMessage(Message msg, ArrayList<Message> listmsg) {
		if(listmsg == null){
			listmsg = new ArrayList<Message>();
			listmsg.add(msg);
			return listmsg;
		}
		else{
			listmsg.add(msg);
			return listmsg;
		}
	}
	
	public String afficheAllMess(ArrayList<Message> listmsg) {
		String allMess = "";
		for(int i = 0; i < listmsg.size(); i++) {
			allMess += "[";
			allMess += listmsg.get(i).dateMessage.getHour() + ":";
			allMess += listmsg.get(i).dateMessage.getMinute() + ":";
			allMess += listmsg.get(i).dateMessage.getSecond() + "]";
			allMess += " " + listmsg.get(i).Pseudo;
			allMess += " : " + listmsg.get(i).Texte + "<br>";
		} 
		return allMess;
	}

}
