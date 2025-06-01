// Configuration
const TEXT_FILE_URL = 'qr.txt';
const REFRESH_INTERVAL = 3000; // Check every 3 seconds

let lastContent = '';

function loadFile() {
    // Add cache-buster to prevent browser caching
    const url = `${TEXT_FILE_URL}?t=${new Date().getTime()}`;
    
    fetch(url)
        .then(response => {
            if (!response.ok) throw new Error('Network response was not ok');
            return response.text();
        })
        .then(text => {
            if (text !== lastContent) {
                document.getElementById('content').textContent = text;
                lastContent = text;
            }
        })
        .catch(error => {
            console.error('Error loading file:', error);
            document.getElementById('content').textContent = 
                'Error loading bus information.';
        });
}

// Load immediately and then set up periodic refresh
loadFile();
setInterval(loadFile, REFRESH_INTERVAL);