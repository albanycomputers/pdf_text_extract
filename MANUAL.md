# PDF Text Extract — manual

## Settings page

**Configuration > Media > PDF text extraction** (`admin/config/media/pdf-text-extract`, permission *Administer site configuration*).

- **Ghostscript** shows whether Ghostscript can be run, and its version.
- **Path to Ghostscript**: leave empty to use `gs` (Linux, macOS) or `gswin64c` (Windows) from the system path. Set the full path if the web server cannot find it, e.g. `/usr/bin/gs` or `C:/Program Files/gs/gs10.08.0/bin/gswin64c.exe`.
- **Time limit**: seconds one PDF may take before extraction is stopped (default 60).

The status report has a matching line, so a missing Ghostscript is noticed.

## Field settings

Edit a **File** field (for example *Structure > Content types > Article > Manage fields > PDF*). Under **PDF text extraction**:

- **Text field**: the long text field (*Long text*, or *Long text and summary*) on the same content type that receives the text. *Disabled* turns the module off for this field.
- **Also extract automatically when the content is saved**: extract when a PDF is added or replaced, or when the text field is empty.
- **Replace text already in the text field when the PDF changes**: only with automatic extraction. Leave it off to keep text an editor has typed or corrected; with it on, replacing the PDF replaces the text, and removing the PDF clears it.

## The button

With a text field chosen, the editing form shows **Extract text from PDF** under the file field. It:

1. reads every PDF in the field (several are joined with a blank line),
2. puts the text into the text field on the form, replacing what is there,
3. shows how many characters were found.

Nothing is saved until the form is saved, so the text can be checked and corrected first. A freshly chosen file is uploaded by the button itself; there is no need to press Upload first.

The button only reads PDFs this content already has, or files the editor has just uploaded.

## What gets extracted

Only text the PDF contains. PDFs made from documents (Word, InDesign and so on) have it. Scanned PDFs usually do not, unless OCR was run on them; for those the button reports that the PDF contains no text.

The text is tidied for searching: page layout spacing is collapsed to single spaces and runs of blank lines to one.

It is stored in the **Plain text** format whatever the field's default, because it comes from an uploaded file.

## Search

Core Search indexes every field shown in the *Search index* display mode, or in the *Default* display if that mode is not customised. To search the text without showing it to visitors, customise the *Search index* display, show the text field there, and hide it in *Default*.

## For developers

```php
// Text of one PDF file entity; FALSE on failure (logged).
$text = pdf_text_extract_file($file);

// Text of several, joined with blank lines.
$text = pdf_text_extract_files($files);

// Write text into a long text field, as plain text.
pdf_text_extract_set_text('node', $node, 'field_pdf_text', $text);
```
