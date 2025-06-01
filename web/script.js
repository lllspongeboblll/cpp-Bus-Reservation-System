// Configuration
const TEXT_FILE_URL = 'QR.txt';
const REFRESH_INTERVAL = 3000; // Check every 3 seconds

function loadFile() {
    // Add cache-buster to prevent browser caching
    const url = `${TEXT_FILE_URL}?t=${new Date().getTime()}`;
    
    fetch(url)
        .then(response => {
            if (!response.ok) throw new Error('Network response was not ok');
            return response.text();
        })
        .then(text => {
            const data = parseTicketData(text);
            updateTicketDisplay(data);
        })
        .catch(error => {
            console.error('Error loading file:', error);
            document.getElementById('ticket-content').innerHTML = `
                <div class="ticket-row">
                    <div class="ticket-value">Error loading ticket data</div>
                </div>
            `;
        });
}

function parseTicketData(text) {
    const lines = text.split('\n');
    const data = {};
    
    lines.forEach(line => {
        if (line.includes(':')) {
            const [key, value] = line.split(':').map(item => item.trim());
            data[key] = value;
        }
    });
    
    return data;
}

function updateTicketDisplay(data) {
    let seatsHtml = '';
    if (data['Seats']) {
        seatsHtml = data['Seats'].split(';').map(seat => 
            `<div class="seat">${seat}</div>`
        ).join('');
    }
    
    const html = `
        <div class="ticket-row">
            <div class="ticket-label">Bus Line</div>
            <div class="ticket-value">${data['Bus_line'] || 'N/A'}</div>
        </div>
        <div class="ticket-row">
            <div class="ticket-label">Bus Type</div>
            <div class="ticket-value">${data['Bus_type'] || 'N/A'}</div>
        </div>
        <div class="ticket-row">
            <div class="ticket-label">Departure Time</div>
            <div class="ticket-value">${data['Time'] || 'N/A'}</div>
        </div>
        <div class="ticket-row">
            <div class="ticket-label">Booked Seats</div>
            <div class="seats">${seatsHtml}</div>
        </div>
        <div class="price">
            ${data['price'] ? 'EGP ' + data['price'] : 'N/A'}
        </div>
    `;
    
    document.getElementById('ticket-content').innerHTML = html;
}

// Load immediately and then set up periodic refresh
loadFile();
setInterval(loadFile, REFRESH_INTERVAL);