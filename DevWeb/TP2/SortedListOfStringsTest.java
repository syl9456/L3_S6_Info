package tp2;

public class SortedListOfStringsTest {

	public static void main(String[] args) {
		
		/* EXO 1 - 2 */
		
		System.out.println();
		System.out.println("*********** EXERCICE 1 & 2 ************");
		System.out.println();
		
		SortedListOfString<String> maListe1 = new SortedListOfString<String>();
		
		maListe1.add("Florian");
		maListe1.add("Sylvain");
		maListe1.add("Jocelyn");
		maListe1.add("Jeoffrey");
		maListe1.add("Arthur");
		
		System.out.println(maListe1.toString());
		
		/* EXO 3 */
		
		System.out.println();
		System.out.println("*********** EXERCICE 3 ************");
		System.out.println();
		
		SortedListOfStringsUsingDelegation<String> maListe2 = new SortedListOfStringsUsingDelegation<String>();
		
		maListe2.add("Florian");
		maListe2.add("Sylvain");
		maListe2.add("Jocelyn");
		maListe2.add("Jeoffrey");
		maListe2.add("Arthur");
		
		System.out.println(maListe2.toString());
		
		/* EXO 4 */
		
		System.out.println();
		System.out.println("*********** EXERCICE 4 ************");
		System.out.println();
		
		SortedList<Integer> listeInt = new SortedList<Integer>();
		SortedList<String> listeString = new SortedList<String>();
		SortedList<Boolean> listeBool = new SortedList<Boolean>();
		SortedList<Character> listeChar = new SortedList<Character>();
		
		listeInt.add(16);
		listeInt.add(4);
		listeInt.add(15);
		listeInt.add(23);
		listeInt.add(8);
		listeInt.add(42);
		System.out.println(listeInt.toString());
		
		listeString.add("Chaussure");
		listeString.add("Babouche");
		listeString.add("Malabar");
		listeString.add("Alcool");
		System.out.println(listeString.toString());
		
		listeBool.add(true);
		listeBool.add(true);
		listeBool.add(false);
		listeBool.add(false);
		listeBool.add(true);
		System.out.println(listeBool.toString());
		
		listeChar.add('z');
		listeChar.add('t');
		listeChar.add('g');
		listeChar.add('s');
		listeChar.add('q');
		listeChar.add('i');
		System.out.println(listeChar.toString());
		
		/* EXO 5 */
		
		System.out.println();
		System.out.println("*********** EXERCICE 5 ************");
		System.out.println();
		
		SortedListUsingDelegation<Integer> listeIntDeleg = new SortedListUsingDelegation<Integer>();
		SortedListUsingDelegation<String> listeStringDeleg = new SortedListUsingDelegation<String>();
		SortedListUsingDelegation<Boolean> listeBoolDeleg = new SortedListUsingDelegation<Boolean>();
		SortedListUsingDelegation<Character> listeCharDeleg = new SortedListUsingDelegation<Character>();
		
		listeIntDeleg.add(16);
		listeIntDeleg.add(4);
		listeIntDeleg.add(15);
		listeIntDeleg.add(23);
		listeIntDeleg.add(8);
		listeIntDeleg.add(42);
		System.out.println(listeIntDeleg.toString());
		
		listeStringDeleg.add("Chaussure");
		listeStringDeleg.add("Babouche");
		listeStringDeleg.add("Malabar");
		listeStringDeleg.add("Alcool");
		System.out.println(listeStringDeleg.toString());
		
		listeBoolDeleg.add(true);
		listeBoolDeleg.add(true);
		listeBoolDeleg.add(false);
		listeBoolDeleg.add(false);
		listeBoolDeleg.add(true);
		System.out.println(listeBoolDeleg.toString());
		
		listeCharDeleg.add('z');
		listeCharDeleg.add('t');
		listeCharDeleg.add('g');
		listeCharDeleg.add('s');
		listeCharDeleg.add('q');
		listeCharDeleg.add('i');
		System.out.println(listeCharDeleg.toString());
		
		System.out.println();
		System.out.println("Test add 17 :");
		listeIntDeleg.add(17);
		System.out.println(listeIntDeleg.toString());
		
		System.out.println();
		System.out.println("Test get 3 :");
		System.out.println(listeIntDeleg.get(3));
		
		System.out.println();
		System.out.println("Test peek :");
		System.out.println(listeIntDeleg.peek());
		
		System.out.println();
		System.out.println("Test clear :");
		listeIntDeleg.clear();
		System.out.println(listeIntDeleg.toString());
	}

}
