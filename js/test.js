var misurazioni=[]

function fetchElenco() {
    let url = "http://localhost:5000";
    fetch(url)
    .then(response => response.json())
    .then(data =>  {
        misurazioni = data;
        // ShowTabella
        console.log(misurazioni)
      });
  }
  
fetchElenco();