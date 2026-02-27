res = "";
document.querySelectorAll('#table td.large a').forEach(a => {
  // res += '=HIPERLINK(\"' + a.href + '\"; \"' + a.textContent + '\")\n';
  res += a.ref + '\n'
});
console.log(res);
