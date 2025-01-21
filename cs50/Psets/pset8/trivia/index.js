function Answer(button, status, feedbackId) {
    const feedback = document.getElementById(feedbackId);
    if (status) {
        button.style.backgroundColor = 'green';
        feedback.textContent = '¡Correcto!';
        feedback.classList.add('correct');
        feedback.classList.remove('incorrect');
    } else {
        button.style.backgroundColor = 'red';
        feedback.textContent = 'Incorrecto';
        feedback.classList.add('incorrect');
        feedback.classList.remove('correct');
    }
}

    function FreeResponse(){
        const input = document.getElementById("01");
        const feedback = document.getElementById("02");
        const correctAns = 'Hiraishin';

        if (input.value.trim().toLowerCase() === correctAns.toLowerCase()){
            input.style.backgroundColor = 'green';
            feedback.textContent = '¡Correcto!';
            feedback.classList.add('correct');
            feedback.classList.remove('incorrect');
        }
        else{
            input.style.backgroundColor = 'red';
            feedback.textContent = 'Incorrecto';
            feedback.classList.add('incorrect');
            feedback.classList.remove('correct');
        }
    }
