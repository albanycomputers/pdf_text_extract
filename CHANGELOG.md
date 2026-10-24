# Changelog

## 1.0.0-alpha1 (unreleased)

- First version. Extracts the text of PDFs in a file field into a chosen
  long text field: with an "Extract text from PDF" button on the editing
  form, and optionally automatically on save.
- Ghostscript (`txtwrite`) does the extraction, run without a shell with a
  time limit; settings page and status report check.
- Extracted text is always stored in the Plain text format.
