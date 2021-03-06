const API_BASE = 'https://teaching.alhinds.com/static/'

export function getJSON (path) {
    return fetch(API_BASE + path)
         .then(res => res.json())
         .catch(err => console.error(err))
}

export function getFile(path) {
   return fetch(API_BASE + path)
        .then(res => res.text())
        .catch(err => console.error(err))
}

export function toCaps (file) {
   let f = file.split('')
   f[0] = f[0].toUpperCase()
   f = f.join('')
   return f
}
