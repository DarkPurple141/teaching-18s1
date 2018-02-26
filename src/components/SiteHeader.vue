<template lang="html">
  <header>
     <nav>
        <h1 class="logo">
           <router-link :to="{ name: 'Home'}">18s1</router-link>
        </h1>
        <ul class="nav">
           <li v-for="course in courses" :key="course.title">
             <router-link :to="{ name: 'Course', params: { course: course.link }}">
                {{ course.title }}
             </router-link>
           </li>
        </ul>
     </nav>
  </header>
</template>

<script>
export default {
   data() {
      return {
         courses: [
            {
               title: 'COMP1511',
               link: 'comp1511'
            },
            {
               title: 'COMP1521',
               link: 'comp1521'
            }
         ]
      }
   }
}
</script>

<style lang="less" scoped>
@import '../assets/colors.less';

header {
  display: flex;
  flex-direction: row;
  background-color: @primary-color-dark;
  color: @base-text;
}

nav {
  position: relative;
  width: 100%;
  display: flex;
  align-items: center;
  background-color: @primary-color;
  margin-top: 8px;
  height: 70px;
}

a {
   text-decoration: none;
   color: @base-text;
}

.logo {
   padding: 0px 20px;
   width: 20%;
}

.nav {
   width: 80%;
   display: flex;
   justify-content: flex-end;
}

ul {
   font-weight: 600;
   list-style-type: none;
}

li {
   padding: 10px;
   margin: 0 5px;
   display: inline-block;
}

a:hover {
   color: @border;
}

</style>
