int wordlists::size () {
  return map.size();
}

bool wordlists::empty () {
  return map.empty();
}

word wordlists::add (const category* key, const word* newVocab)
{
  map[key].push_back (newVocab);
  return newVocab;
}

word wordlists::remove (const category* key, const word* oldVocab)
{
  auto search = map.find(category);
  if (search != map.end()) {
    map.erase(oldVocab);
    return true;
  }
  else
    return false;
}

wordlist wordlists::get (const category* key)
{
  map.find(key)
  

}
