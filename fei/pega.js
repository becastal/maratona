res = "";
document.querySelectorAll('#table td.large a').forEach(a => {
  res += '=HIPERLINK(\"' + a.href + '\"; \"' + a.textContent + '\")\n';
});
console.log(res);
