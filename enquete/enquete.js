'use: strict';

/*Qual o melhor sistema operacional para uso em servidores?
As possíveis respostas são:

1- Windows Server.
2 - Unix.
3 - Linux.
4 - Netware.
5 - Mac OS.
6 - Outro.

O programa deverá ler os valores até ser informado o valor 0, que encerra a entrada dos dados. Não deverão ser aceitos valores além dos válidos para o programa (0 a 6).
Após os dados terem sido completamente informados, o programa deverá calcular a percentual de cada um dos concorrentes.
Ao final, devem ser mostrados todos os sistemas operacionais com a quantidade de votos e o percentual de cada um.*/

let votos = {
    windows: 0,
    unix: 0,
    linux: 0,
    netware: 0,
    mac: 0,
    outro: 0
}


function fazerContagem (event, form) {
    event.preventDefault();
    form = form.querySelector('input[type="number"]').value;
    console.log(form);
    html = document.getElementById("html")

    document.getElementById("button").disabled = true;
    document.getElementById("input").disabled = true;

    switch (form) 
        {
            case "1":
                votos.windows++;
                html.style.backgroundImage ="url('img/windows.jpg')"
                break;
            case "2":
                votos.unix++;
                html.style.backgroundImage ="url('img/unix.jpg')"
                break;
            case "3":
                votos.linux++;
                html.style.backgroundImage ="url('img/linux.jpg')"
                break;
            case "4":
                votos.netware++;
                html.style.backgroundImage ="url('img/netware.jpg')"
                break;
            case "5":
                votos.mac++;
                html.style.backgroundImage ="url('img/macos.png')"
                break;
            case "6":
                votos.outro ++;
                html.style.backgroundImage ="url('img/outro.jpg')"
                break;
            case "0":
                let votosPorcento = [];
                let votosArray = [];
                let total = votos.windows + votos.unix + votos.linux + votos.netware + votos.mac + votos.outro;
                for(let prop in votos) {
                    votosAtuais = votos[prop];
                    let porcentagem = ((100 * votosAtuais) / total).toFixed(2);
                    votosPorcento.push(porcentagem);
                    votosArray.push(votos[prop]);   
                }
                if(total == 0) {
                    votosPorcento = [0, 0, 0, 0, 0, 0]
                }
                for(let i = 0; i < 6; i++) {
                    let resultado = document.getElementById(`${i+1}`);
                    htmlAtual = resultado.innerHTML;
                    resultado.innerHTML = `${htmlAtual} <span style="color:red">Recebeu ${votosArray[i]} voto(s), ${votosPorcento[i]}%<span>`
                }
                document.getElementById("button").disabled = true;
                document.getElementById("input").disabled = true;
                return true;
        }
        setTimeout(function () {
            document.getElementById("button").disabled = false;
            input = document.getElementById("input")
            input.disabled = false;
            input.value = "";
            input.focus();
        }, 500) 
}       