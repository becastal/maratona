res = "";
document.querySelectorAll('.pg-vertical a').forEach(a => {
  // res += '=HIPERLINK(\"' + a.href + '\"; \"' + a.textContent + '\")\n';
  res += a.href + '\n'
});
