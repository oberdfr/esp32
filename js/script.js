const body = document.getElementById('body')
let firstTime = 0

function converti(misurecurr){
    let  misure_nuovo = []
    for (let i=0; i< misurecurr.length; i++) {
        let misura = misurecurr[i];
        let nuovamisura = {
            id: misura.id,
            aula: misura.aula,
            giorno: new Date(misura.giorno).toDateString(),
            ora: misura.ora,
            valore: misura.valore + "°C",
        }

        misure_nuovo.push(nuovamisura);
        
    }

    return misure_nuovo

}




function tabella(misurecurr){
    //if (firstTime=0) {
    //   table=null
    //}
    firstTime = 1
    let i = misurecurr.length 

    let table = document.createElement('table')
    table.setAttribute('id','tabella')

    let tr = document.createElement('tr')

    let txt = 0
    let content = 0
    let txtinit = 0
    let contentinit = 0

        for(let j=0; j<5; j++){
            
            switch (j){
                case 0:
                    contentinit = "Id"
                    break;
                
                case 1:
                    contentinit = "Ora"
                    break;

                case 2:
                    contentinit = "Aula"
                    break;
                
                case 3:
                    contentinit = "Data"
                    break;
            
                case 4:
                    contentinit = "Temperatura"
                    break;
                    
                }
            
            txtinit = document.createTextNode(contentinit)

            let td = document.createElement('td')
            td.setAttribute('class','headertab')

            td.append(txtinit)
            tr.append(td) 
            table.append(tr)
            
            
        }
        
        for(let u=0; u<i; u++){ 
            tr = document.createElement('tr')
            for(let k=0; k<5; k++){
            
                switch (k){
                    case 0:
                        content = misurecurr[u].id
                        break;
                    
                    case 1:
                        content = misurecurr[u].ora
                        break;
                    
                    case 2:
                        content = misurecurr[u].aula
                        break;
                    
                    case 3:
                        content = misurecurr[u].giorno
                        break;
                
                    case 4:
                        content = misurecurr[u].valore
                        break;
                    }
                
                txt = document.createTextNode(content)

                let td = document.createElement('td')
                td.append(txt)
                tr.append(td)
            
            }
            table.append(tr)
        }
         
    return table
}


let div = document.querySelector('#risultato')



function getDateValue(){
    var imputData = document.getElementById('dataImput')
    var dataSelezionata = imputData.value;
    console.log("selected date: " + dataSelezionata)
}

let bottoneData = document.getElementById('bottoneData') 
bottoneData.addEventListener('click', getDateValue())

//input date control su w3school

function fetchElenco() {
    let url = "http://10.25.0.15:5050";
    fetch(url)
    .then(response => response.json())
    .then(data =>  {
        misurazioni = data;
        // ShowTabella
            let t1 = tabella(converti(misurazioni))
            div.append(t1)
            body.append(div)
        console.log(misurazioni)
      });
  }
  
fetchElenco();
