$(function() {
    getItems().then(function(items) {
        items.forEach(renderItem);
    });

    $('#theForm').submit(function(e) {
        e.preventDefault();

        postItem({
            value: $('#theValue').val()
        })
        .then(renderItem)
        .then(resetForm);
    });

    function getItems() {
        return $.get('/api/items');
    }

    function postItem(item) {
        return $.ajax('/api/items', {
            method: 'POST',
            contentType: 'application/json',
            data: JSON.stringify(item),
            dataType: 'json'
        });
    }

    function renderItem(item) {
        $('#theList').append($('<li>').text(item.value));
    }

    function resetForm() {
        $('#theValue').val('').focus();
    }
});
