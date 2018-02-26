import Vue from 'vue'
import Router from 'vue-router'
import Home from '@/pages/Home'
import Course from '@/pages/Course'
import Class from '@/pages/Class'
import Lab from '@/pages/Lab'

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
    },
    {
      path: '/course/:course/:class',
      name: 'Class',
      component: Class,
      props: (route) => ({
         course: route.params.course,
         cls: route.params.class
      })
    },
    {
      path: '/course/:course/:class/:week',
      name: 'Lab',
      component: Lab,
      props: (route) => ({
         course: route.params.course,
         cls: route.params.class,
         week: route.params.week
      })
    }
  ]
})
