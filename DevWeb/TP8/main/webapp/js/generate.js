/**
 *  DOFFEMONT Florian
 */
 
 /*********************** EXERCICE 1  ***********************/
 
 var nbElement = document.querySelectorAll("*").length;
 var nbChildNode = document.childNodes.length;
 
 window.alert("Nombre d'element  [" + 
 			   nbElement + 
 			   "] ||| Nombre de noeud enfants [" + 
 			   nbChildNode + "]");
 
/*********************** EXERCICE 2  ***********************/
  
function remplirLaGrille(){
	var elemGrille = document.getElementById("laGrille");
	for(var i = 0; i < 25; i++){
		var ElementDiv = document.createElement("div");
		var text = document.createTextNode(i);
		ElementDiv.appendChild(text);
		elemGrille.appendChild(ElementDiv);
	}
}

remplirLaGrille();

/*********************** EXERCICE 3  ***********************/

function ajouterDesdivs(elementARemplir){
	for(var i = 0; i < 25; i++){
		var ElementDiv = document.createElement("div");
		var text = document.createTextNode(i);
		ElementDiv.appendChild(text);
		elementARemplir.appendChild(ElementDiv);
	}
	updateLesDivsDeTous();
}

function setupClickToFill(){
	var listeCTF = document.querySelectorAll("section.clickToFill");
	for(var y = 0; y < listeCTF.length; y++){
		ajouterDesdivs(listeCTF.item(y));
	}
	document.removeEventListener("click", setupClickToFill);
}

document.addEventListener("click", setupClickToFill);

/*********************** EXERCICE 4  ***********************/

let model = [];

function initModel(){
	for(var i = 0; i < 25; i++){
		model.push(Math.random() < 0.5);
	}
}

initModel();

function updateLesDivs(elem){
	console.log(model);
	for(var i = 0; i < elem.children.length; i++){
		if(model[i] == true){
			elem.children[i].classList.add("on");
		}
		else{
			if(elem.children[i].classList){
				elem.children[i].classList.remove("on");
			}
		}
		elem.children[i].onclick = function(){
			if(model[i] == true){
				model[i] = false;
			}
			else{
				model[i] = true;
			}
			updateLesDivsDeTous();
		};
	}	
}

function updateLesDivsDeTous(){
	var listeSection = document.querySelectorAll("section");
	for(var i = 0; i < listeSection.length; i++){
		 updateLesDivs(listeSection[i]);
	}
	
}


