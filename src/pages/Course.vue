<template lang="html">
<section class="content">
   <section-header :name="course"/>
   <article class="content-body">
      <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p>
   </article>
</section>
</template>

<script>
import SectionHeader from '@/components/SectionHeader'

export default {
   components: { SectionHeader },
   props: {
      course: String,
      required: true
   }
}
</script>

<style lang="less" scoped>
@import '../assets/colors.less';

.content {
   width: 95%;
   margin: 0 auto;
}

.content-body {
   margin: 20px;
   line-height: 1.7;
   text-align: left;
   color: @secondary-text;
}

</style>
