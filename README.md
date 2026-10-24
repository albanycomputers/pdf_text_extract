# PDF Text Extract

Copies the text of PDF files uploaded to a file field into a long text field on the same content, so that site search can find what is inside the PDFs.

Choose the text field in the file field's settings. Editors then get an **Extract text from PDF** button under the file field: it fills the text field straight away, so they can check and correct the text before saving. Optionally, the text is also extracted automatically whenever the content is saved with a new PDF.

The text is read with Ghostscript, which most hosts that can make images from PDFs already have. Only text the PDF already contains is read: a scanned PDF without a text layer gives nothing (that needs OCR, which this module does not do).

Works with any entity that has fields, and alongside other PDF modules such as PDF to Image and PDF Flipbook.

## Requirements

- Backdrop CMS 1.x
- PHP 8.0 or later, with `proc_open()` allowed
- [Ghostscript](https://www.ghostscript.com/) installed on the server

## Installation

Install this module using the official Backdrop CMS instructions at https://docs.backdropcms.org/documentation/extend-with-modules

Then:

1. Check **Reports > Status report**: the "PDF Text Extract: Ghostscript" line should show a version. If not, set the path to Ghostscript at **Configuration > Media > PDF text extraction**.
2. Add a **Long text** field to the content type for the text (it can be hidden from display; search still indexes it).
3. Edit the **File** field and, under **PDF text extraction**, choose that text field.

See MANUAL.md for the settings in detail.

## Security

The extracted text comes from uploaded files, so it is always stored in the **Plain text** format and never rendered as HTML. Ghostscript runs with `-dSAFER` and without a shell.

## Issues

Bugs and feature requests should be reported in the issue queue: https://github.com/backdrop-contrib/pdf_text_extract/issues

## Current Maintainer(s)

- Steve Moorhouse (albanycomputers) (https://github.com/albanycomputers)
- Seeking additional maintainers and contributors.

## Credits

- Steve Moorhouse - Zulip (DrAlbany)
- Assisted by AI

## Sponsorship

- Albany Computer Services (https://www.albany-computers.co.uk)
- Albany Web Design (https://www.albanywebdesign.co.uk)
- Albany Hosting (https://www.albany-hosting.co.uk)

## License

This project is GPL v2 software. See the LICENSE.txt file in this directory for complete text.
