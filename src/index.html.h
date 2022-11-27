const char *indexHtml = R"====(
<html> <!-- original .html file -->
<head>
	<meta charset='utf-8'>
	<meta name='viewport' content='width=device-width, initial-scale=1'>
	<title>ESP Wake on Lan Page</title>
	<link href='https://fonts.googleapis.com/css?family=Open+Sans:300,400,600,700' rel='stylesheet'>
	<link href='https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/css/bootstrap.min.css' rel='stylesheet'>
	<link href='https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.2.1/css/all.min.css' rel='stylesheet'>
	<style type='text/css'>
		:root {
		    --font-family-sans-serif: Open Sans, sans-serif;
		    --font-family-monospace: SFMono-Regular, Menlo, Monaco, Consolas, 'Liberation Mono', 'Courier New', monospace;
		}
		*,
		*::before,
		*::after {
		    box-sizing: border-box;
		}
		@-ms-viewport {
		    width: device-width;
		}
		body {
		    font-family: Open Sans, sans-serif;
		    font-size: 1rem;
		    font-weight: 400;
		    line-height: 1.5;
		    margin: 0;
		    text-align: left;
		    color: #525f7f;
		    background-color: #f8f9fe;
		}
		h2,
		h3 {
		    margin-top: 0;
		    margin-bottom: .5rem;
		}
		p {
		    margin-top: 0;
		    margin-bottom: 1rem;
		}
		table {
		    border-collapse: collapse;
		}
		th {
		    text-align: inherit;
		}
		h2,
		h3,
		.h2,
		.h3 {
		    font-family: inherit;
		    font-weight: 600;
		    line-height: 1.5;
		    margin-bottom: .5rem;
		    color: #32325d;
		}
		h2,
		.h2 {
		    font-size: 1.25rem;
		}
		h3,
		.h3 {
		    font-size: 1.0625rem;
		}
		.container {
		    width: 100%;
		    margin-right: auto;
		    margin-left: auto;
		    padding-right: 15px;
		    padding-left: 15px;
		}
		@media (min-width: 576px) {
		    .container {
		        max-width: 540px;
		    }
		}
		@media (min-width: 768px) {
		    .container {
		        max-width: 720px;
		    }
		}
		@media (min-width: 992px) {
		    .container {
		        max-width: 960px;
		    }
		}
		@media (min-width: 1200px) {
		    .container {
		        max-width: 1140px;
		    }
		}
		.row {
		    display: flex;
		    margin-right: -15px;
		    margin-left: -15px;
		    flex-wrap: wrap;
		}
		.table {
		    width: 100%;
		    margin-bottom: 1rem;
		    background-color: transparent;
		    margin-bottom: 0;
		}
		.table th,
		.table td {
		    padding: 1rem;
		    vertical-align: top;
		    border-top: 1px solid #e9ecef;
		}
		.table thead th {
		    vertical-align: bottom;
		    border-bottom: 2px solid #e9ecef;
		}
		.table tbody + tbody {
		    border-top: 2px solid #e9ecef;
		}
		.table-dark,
		.table-dark > th,
		.table-dark > td {
		    background-color: #c1c2c3;
		}
		.table .thead-dark th {
		    color: #f8f9fe;
		    border-color: #1f3a68;
		    background-color: #172b4d;
		}
		.table .thead-light th {
		    color: #8898aa;
		    border-color: #e9ecef;
		    background-color: #f6f9fc;
		}
		.table-responsive {
		    display: block;
		    overflow-x: auto;
		    width: 100%;
		    -webkit-overflow-scrolling: touch;
		    -ms-overflow-style: -ms-autohiding-scrollbar;
		}
		.card {
		    position: relative;
		    display: flex;
		    flex-direction: column;
		    min-width: 0;
		    word-wrap: break-word;
		    border: 1px solid rgba(0, 0, 0, .05);
		    border-radius: .375rem;
		    background-color: #fff;
		    background-clip: border-box;
		}
		.card-header {
		    margin-bottom: 0;
		    padding: 1.25rem 1.5rem;
		    border-bottom: 1px solid rgba(0, 0, 0, .05);
		    background-color: #fff;
		}
		.card-header:first-child {
		    border-radius: calc(.375rem - 1px) calc(.375rem - 1px) 0 0;
		}
		.card-footer {
		    padding: 1.25rem 1.5rem;
		    border-top: 1px solid rgba(0, 0, 0, .05);
		    background-color: #fff;
		}
		.card-footer:last-child {
		    border-radius: 0 0 calc(.375rem - 1px) calc(.375rem - 1px);
		}
		.shadow {
		    box-shadow: 0 0 2rem 0 rgba(136, 152, 170, .15) !important;
		}
		.mb-0 {
		    margin-bottom: 0 !important;
		}
		.mt-5 {
		    margin-top: 3rem !important;
		}
		.py-4 {
		    padding-bottom: 1.5rem !important; 
		  padding-top: 1.5rem !important;
		}
		.btn {
		    font-size: .875rem;
		    position: relative;
		    transition: all .15s ease;
		    letter-spacing: .025em;
		    text-transform: none;
		    will-change: transform;
		}
		.btn:hover {
		    transform: translateY(-1px);
		    box-shadow: 0 7px 14px rgba(50, 50, 93, .1), 0 3px 6px rgba(0, 0, 0, .08);
		}
		.btn:not(:last-child) {
		    margin-right: .5rem;
		}
		.btn i:not(:first-child) {
		    margin-left: .5rem;
		}
		.btn-sm {
		    font-size: .75rem;
		}
		.btn-icon-only.btn-sm {
		    width: 2rem;
		    height: 2rem;
			padding-top: 9px;
		}
		.table thead th {
		    font-size: .65rem;
		    padding-top: .75rem;
		    padding-bottom: .75rem;
		    letter-spacing: 1px;
		    text-transform: uppercase;
		    border-bottom: 1px solid #e9ecef;
		}
		.table th {
		    font-weight: 600;
		}
		.table td,
		.table th {
		    font-size: .9rem;
		    white-space: nowrap;
		}
		.table.align-items-center td,
		.table.align-items-center th {
		    vertical-align: middle;
		}
		.card .table td,
		.card .table th {
		    padding-right: 1.5rem;
		    padding-left: 1.5rem;
		}
		 @media only screen and (max-width: 900px) {
		   tr th:nth-child(2),
		   tr td:nth-child(2),
		   tr th:nth-child(3),
		   tr td:nth-child(3){
		     display: none;
		   }
		}
		.right{
		  float:right;
		}
	</style>
</head>
<body>
	  <div class='main-content'>
    <div class='container mt-5'>
      <h2 class='mb-4'>ESP Wake on Lan</h2><div class='row'>
        <div class='col'>
          <div class='card shadow'>
            <div class='card-header border-0 '>
              <h3 class='mb-0'>Computer List
                <button class='btn btn-sm btn-danger right' data-bs-toggle='modal' data-bs-target='#addComputerModal'>Add New</button>
              </h3>
            </div>
            <div class='table-responsive'>
              <table class='table align-items-center'>
                <thead class='thead-light'>
                  <tr>
                    <th scope='col'>Name</th>
                    <th scope='col'>MAC</th>
                    <th scope='col'>Port</th>
                    <th scope='col'>Action</th>
                    <th scope='col'></th>
                  </tr>
                </thead>
                <tbody>
                </tbody>
              </table>
            </div>
            <div class='card-footer py-4'></div>
          </div>
        </div>
      </div>
    </div>
  </div>
  <div class='modal fade' id='addComputerModal' tabindex='-1' aria-labelledby='exampleModalLabel' aria-hidden='true'>
  <div class='modal-dialog'>
    <div class='modal-content'>
        <form method='get' action='AddNew'>
        <div class='modal-header'>
            <h1 class='modal-title fs-5' id='exampleModalLabel'>Add new computer</h1>
            <button type='button' class='btn-close' data-bs-dismiss='modal' aria-label='Close'></button>
        </div>
        <div class='modal-body'>
            <div class='mb-3'>
            <label for='exampleFormControlInput1' class='form-label'>Name</label>
            <input type='text' name='name' class='form-control' id='exampleFormControlInput1' placeholder='Main Computer'>
            </div>
            <div class='mb-3'>
            <label for='exampleFormControlInput2' class='form-label'>MAC</label>
            <input type='text' name='mac' class='form-control' id='exampleFormControlInput2' placeholder='MM:MM:MM:SS:SS:SS'>
            </div>
            <div class='mb-3'>
            <label for='exampleFormControlInput3' class='form-label'>Port</label>
            <input type='number' name='port' class='form-control' id='exampleFormControlInput3' placeholder='9' value='9'>
            </div>
        </div>
        <div class='modal-footer'>
            <button type='button' class='btn btn-secondary' data-bs-dismiss='modal'>Close</button>
            <button type='submit' class='btn btn-primary'>Save changes</button>
        </div>
        </div>
    </form>
  </div>
</div>
  </div>
	<script type='text/javascript' src='https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js'></script>
	<script type='text/javascript'>
		document.addEventListener('DOMContentLoaded', function(event) {
			let r = new XMLHttpRequest();
			r.open("GET", '/getData', false);
			r.send(null);
			console.log(r.responseText);
			if(!r.responseText) {
				let row = document.querySelector('table').insertRow();
				cell1 = row.insertCell(0);
                cell1.colSpan = "5";
				cell1.innerHTML = "No computer yet 😢";
				return;
			};
			r.responseText.split(';').forEach((item)=>{
				let arr = item.split(',');
				let row = document.querySelector('table').insertRow();
				cell1 = row.insertCell(0);
				cell2 = row.insertCell(1);
				cell3 = row.insertCell(2);
				cell4 = row.insertCell(3);
				cell5 = row.insertCell(4);
				cell1.innerHTML = arr[0];
				cell2.innerHTML = arr[1];
				cell3.innerHTML = arr[2];
				cell4.innerHTML = `<a href=\"/remove?item=${arr}\" class='btn btn-sm btn-danger btn-icon-only'><i class='fa-solid fa-trash'></i></a>`;
				cell5.innerHTML = `<a href=\"/wake?name=${arr[0]}&mac=${arr[1]}&port=${arr[2]}\" class='btn btn-sm btn-success text-dark'>Wake</a>`;
			});

		});
	</script>
</body>
</html> <!-- end .html -->
)===="; // added by script