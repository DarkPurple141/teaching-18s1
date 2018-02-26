export function getJSON (path) {
    return fetch(path)
         .then(res => res.json())
         .catch(err => console.error(err))
}

export function toCaps (file) {
   let f = file.split('')
   f[0] = f[0].toUpperCase()
   f = f.join('')
   return f
}
