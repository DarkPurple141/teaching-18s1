import Vue from 'vue'
import Router from 'vue-router'
import Home from '@/pages/Home'
import Course from '@/pages/Course'

Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/',
      name: 'Home',
      component: Home
    },
    {
      path: '/course/:course',
      name: 'Course',
      component: Course,
      props: (route) => ({
         course: route.params.course
      })
    }
  ]
})
