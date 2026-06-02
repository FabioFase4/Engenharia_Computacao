document.addEventListener('DOMContentLoaded', () => {
    
    // 1. Scroll Suave Universal
    // Seleciona todos os links de navegação e botões de ação
    const scrollTargets = document.querySelectorAll('.nav-links a, .btn-grad, .logo');

    scrollTargets.forEach(el => {
        el.addEventListener('click', (e) => {
            let targetId = el.getAttribute('href')?.substring(1);

            // Tratamento especial para botões que não são links (baseado no ID)
            if (!targetId) {
                if (el.id === 'exploreBtn') targetId = 'areas';
                if (el.id === 'saibaMaisBtn') targetId = 'formacao'; // Ajustado para a seção de trilhas
                if (el.id === 'contactBtn') targetId = 'contato';
                if (el.classList.contains('logo')) {
                    e.preventDefault();
                    window.scrollTo({ top: 0, behavior: 'smooth' });
                    return;
                }
            }

            if (targetId) {
                e.preventDefault();
                const targetElement = document.getElementById(targetId);
                if (targetElement) {
                    targetElement.scrollIntoView({ behavior: 'smooth', block: 'start' });
                }
            }
        });
    });

    // 2. Observer para Animações (Fade-in)
    // Mais eficiente que o evento 'scroll' direto
    const fadeOptions = {
        threshold: 0.15, // Ativa quando 15% do elemento aparece
        rootMargin: "0px 0px -50px 0px"
    };

    const fadeObserver = new IntersectionObserver((entries, observer) => {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                entry.target.classList.add('revealed');
                observer.unobserve(entry.target); // Para de observar após animar
            }
        });
    }, fadeOptions);

    document.querySelectorAll('.fade-up').forEach(el => fadeObserver.observe(el));

    // 3. Feedback Visual do Botão de Contato (Toast)
    const contactBtn = document.getElementById('contactBtn');
    if (contactBtn) {
        contactBtn.addEventListener('click', () => {
            showToast('📩 Mensagem enviada para o laboratório!');
        });
    }

    function showToast(message) {
        const toast = document.createElement('div');
        toast.className = 'toast-notification'; // Estilize isso no seu CSS
        toast.textContent = message;
        document.body.appendChild(toast);
        
        // Estilo rápido via JS (ou mova para o CSS)
        Object.assign(toast.style, {
            position: 'fixed', bottom: '20px', left: '50%',
            transform: 'translateX(-50%)', backgroundColor: '#1f5e7a',
            color: 'white', padding: '12px 24px', borderRadius: '40px',
            zIndex: '1000', boxShadow: '0 8px 20px rgba(0,0,0,0.2)'
        });

        setTimeout(() => toast.remove(), 3000);
    }
});